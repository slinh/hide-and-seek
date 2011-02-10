#include "common.h"
#include "config.h"
#include "Animation.h"
#include "Functions.h"
#include "ReadFile.h"

namespace psp { namespace engine { namespace object {

TAnimation::TAnimation() :
FAnimState(0),
FStartFrame(0),
FEndFrame(0),
FCurrentFrame(0)
{
}

TAnimation::~TAnimation()
{
}

void TAnimation::LoadAnim(const char* parFile)
{
	io::TReadFile file(parFile);
	s32 filesize = (s32)file.GetSize();

    LAssert(filesize > 0);

	// LONG_BUFFER_SIZE
	c8 wordBuffer[LONG_BUFFER_SIZE];

	c8* buf = NEW_ c8[filesize];
	file.Read((void*)buf, filesize);

	c8* line = buf;
	
	while(line)
	{
		c8* word = line;
		CopyWordLineEnd(wordBuffer, LONG_BUFFER_SIZE, word);

		if((wordBuffer[0] >= '0') && (wordBuffer[0] <= '9'))
		{
			c8 p1[4];
			CopyWordSpaceEnd(p1, 4, wordBuffer);

			c8 p2[4];
			CopyWordSpaceEnd(p2, 4, GetNextWord(wordBuffer));

			c8* p3 = GetNextWord(GetNextWord(wordBuffer));

			core::vector2di anim;
			anim.X = atoi(p2);
			anim.Y = atoi(p3);

			LOGC_3D("Anim Pushed : %d, %d \n", anim.X, anim.Y);

			FAnimFrames.push_back(anim);
		}

		line = GetNextWordLineEnd(line);
	}

	delete buf;

	SetAnimState(0);
}

int TAnimation::Update()
{
	FCurrentFrame++;
	if(FCurrentFrame >= FEndFrame)
		FCurrentFrame = FStartFrame;

	return FCurrentFrame;
}

void TAnimation::SetAnimState(int parState)
{
	LAssert((size_t)parState < FAnimFrames.size());
	FAnimState = parState;
	FStartFrame = FAnimFrames[parState].X;
	FEndFrame = FAnimFrames[parState].Y;

	FCurrentFrame = FStartFrame;

	LOGC_3D("Anim State : %d -  %d to  %d \n", FAnimState, FStartFrame, FEndFrame);
}

} // object namespace
} // namespace object
} // psp namespace
