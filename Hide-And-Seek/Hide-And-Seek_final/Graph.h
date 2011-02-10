#ifndef GRAPH_H
#define GRAPH_H

#include "config.h"
#include "Logger.h"
#include "Node.h"
#include "Singleton.h"

#include "vector3d.h"
#ifdef COMPILE_PSP
	#include <pspctrl.h>
#endif

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/astar_search.hpp>

#ifdef COMPILE_PC
#include <iostream>
#endif

namespace psp { namespace engine { namespace core {

/// Default type of a graph
typedef boost::adjacency_list<						//  Adjacency_list template depending on :
    boost::listS,									//  Type of container for nodes. Here, std::list.
    boost::vecS,									//  Type of container for edges. Here, std::vector.
    boost::bidirectionalS,							//  Type of arcs. Should be boost::directedS.
    Node,											//  Nodes type.
    boost::property < boost::edge_weight_t, int >	//  Edge type
	> Graph;
	
typedef Graph::vertex_descriptor NodeID;			// Vertex

typedef Graph::edge_descriptor   EdgeID;			// Edges
typedef boost::property_map<Graph, boost::edge_weight_t>::type EdgeMap; // Edge map type

typedef boost::graph_traits<Graph>::vertex_iterator NodeIterator; // Iterator on vertex
typedef boost::graph_traits<Graph>::edge_iterator EdgeIterator; // Iterator on edges

class TGridGraph : public TSingleton<TGridGraph, true>
{
public :
    TGridGraph();
	~TGridGraph();

	void Init(u32& parGridWidth, u32& parGridHeight, u32& parGridSpacing, array< array<u32> >& parBlockIds);

	void GetNodePosition(u32& parNodeId, vector2di& parPosition) { parPosition = FGraph[parNodeId].GetPosition(); }
	void GetNodePosition(u32& parNodeId, vector3df& parPosition) { parPosition.X = FGraph[parNodeId].GetPosition().X; parPosition.Y = FGraph[parNodeId].GetPosition().Y; }

	u32 GetNearestNode(const vector2di& parPosition);
	u32 GetNearestNode(const vector3df& parPosition);

	u32 GetNextNodeToGo(u32 parCurrentNode, u32 parDestNode);

private :
	u32 FGridWidth;
	u32 FGridHeight;
	u32 FGridSpacing;

	Graph FGraph;
	
};

// Une instance de cette structure sera lancée en exception quand on aura trouvé un chemin
struct found_goal {};
 
// Le visiteur, dont le but est de définir une fonction examine_vertex qui dit si on est arrivé au but.
// Le but est spécifié via le constructeur.
class astar_goal_visitor : public boost::default_astar_visitor{
public:
    astar_goal_visitor(NodeID goal) : m_goal(goal) {}
 
    void examine_vertex(NodeID u, const Graph& g){ // Le const est important.
        if(u == m_goal)
            throw found_goal(); // On sort en lancant une exception. C'est moche mais c'est comme ça.
        }
private:
    NodeID m_goal;
};

} // core namespace
} // engine namespace
} // psp namespace

#endif // GRAPH_H
