#include "Graph.h"

namespace psp { namespace engine { namespace core {

	TGridGraph::TGridGraph()
		: FGridWidth(0),
		FGridHeight(0),
		FGridSpacing(0)
	{
		SINGLETONREGINSTANCE
	}

	TGridGraph::~TGridGraph()
	{

	}

	void TGridGraph::Init(u32& parGridWidth, u32& parGridHeight, u32& parGridSpacing, array< array<u32> >& parBlockIds)
	{
		FGridWidth = parGridWidth;
		FGridHeight = parGridHeight;
		FGridSpacing = parGridSpacing;

		LOGC_CORE("**********************************\n");
		LOGC_CORE("Create %d x %d graph \n ", parGridWidth, parGridHeight);

		// Creates Vertexes
		for(u32 i=0; i<parGridWidth; ++i)
		{
			for(u32 j=0; j<parGridHeight; ++j)
			{
				unsigned int locIndex = boost::add_vertex(FGraph);
				(FGraph)[locIndex].SetPosition() = vector2di(i*FGridSpacing,j*FGridSpacing);

				//LOGC_CORE("Node %d : %d, %d ", locIndex, i*FGridSpacing, j*FGridSpacing);

				if(parBlockIds[locIndex].size() > 0)
				{
					(FGraph)[locIndex].SetEnabled() = false;
					//LOGC_CORE("DISABLED");
				}
				else
				{
					(FGraph)[locIndex].SetEnabled() = true;
					//LOGC_CORE("ENABLED");
				}
				LOGC_CORE("\n");
			}
		}

		LOGC_CORE("**********************************\n");

		// Set Edges between Vertexes
		for(u32 i=0; i<FGridWidth; ++i)
		{
			for(u32 j=0; j<FGridHeight; ++j)
			{
				NodeID locNodeID = i*FGridHeight + j;
				if((FGraph)[locNodeID].GetEnabled())
				{
					if(i > 0) 
					{
						if((FGraph)[(i-1)*FGridHeight + j].GetEnabled())
							boost::add_edge(locNodeID, (i-1)*FGridHeight + j, FGraph);
					}
					if(i < (FGridWidth-1)) 
					{
						if((FGraph)[(i+1)*FGridHeight + j].GetEnabled())
							boost::add_edge(locNodeID, (i+1)*FGridHeight + j, FGraph);
					}
					if(j > 0) 
					{
						if((FGraph)[i*FGridHeight + j - 1].GetEnabled())
							boost::add_edge(locNodeID, i*FGridHeight + j - 1, FGraph);
					}
					if(j < (FGridHeight-1)) 
					{
						if((FGraph)[i*FGridHeight + j + 1].GetEnabled())
							boost::add_edge(locNodeID, i*FGridHeight + j + 1, FGraph);
					}
				}
			}
		}
	}

	u32 TGridGraph::GetNearestNode(const vector2di& parPosition)
	{
		u32 locX = parPosition.X - (parPosition.X % FGridSpacing);
		u32 locY = parPosition.Y - (parPosition.Y % FGridSpacing);
		vector2di locNodePosition(locX, locY);

		NodeIterator first, last;
		boost::tie(first, last) = boost::vertices(FGraph);

		while(first != last)
		{
			Node N = FGraph[*first];
			if(locNodePosition == N.GetPosition())
				return *first;

			++first;
		}
		return 0;
	}

	u32 TGridGraph::GetNearestNode(const vector3df& parPosition)
	{
		vector2di locNode((int)parPosition.X, (int)parPosition.Y);

		return GetNearestNode(locNode);
	}

	u32 TGridGraph::GetNextNodeToGo(u32 parCurrentNode, u32 parDestNode)
	{
		std::vector<u32> p(boost::num_vertices(FGraph));
		std::vector<u32> d(boost::num_vertices(FGraph));
		std::vector<u32> w(boost::num_vertices(FGraph));

		//boost::dijkstra_shortest_paths( FGraph, s, boost::predecessor_map(&p[0]).distance_map(&d[0]));
		boost::astar_search(FGraph, parCurrentNode, 
							boost::astar_heuristic<Graph, float>(), // Une heuristique bidon qui renvoie toujours 0
							boost::predecessor_map(&p[0]).distance_map(&d[0])); // Voir plus bas

		// Predecessor to find the path
		u32 currentNode, previousNode;
		std::vector<bool> seen(boost::num_vertices(FGraph), false);

		previousNode = parDestNode;
		currentNode = p[previousNode];

		seen[currentNode] = true;
		seen[previousNode] = true;

		LOGC_CORE("Path : (%d)", previousNode);

		while((currentNode != parCurrentNode) /*&& !seen[currentNode]*/)
		{
			previousNode = currentNode;
			LOGC_CORE("<-(%d)", previousNode);
			currentNode = p[previousNode];
			seen[previousNode] = true;
			LOGC_CORE("--");
		}

		LOGC_CORE("<-(%d) \n", currentNode);

		return previousNode;
	}

} // core namespace
} // engine namespace
} // psp namespace