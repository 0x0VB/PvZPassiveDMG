#pragma once
class Object
{
public:
	class LawnApp* LawnApp; //0x0000
	class Game* Game; //0x0004
	char pad_0008[8]; //0x0008
	int XSize; //0x0010
	int YSize; //0x0014
	bool Visible; //0x0018
	char pad_0019[11]; //0x0019
	float XPosition; //0x0024
	float YPosition; //0x0028
	float XVelocity; //0x002C
	float YVelocity; //0x0030
	float Scale; //0x0034
	bool Dead; //0x0038
	char pad_0039[3]; //0x0039
	int FadeTimer; //0x003C
	float XCollect; //0x0040
	float YCollect; //0x0044
	int Ground; //0x0048
	int Age; //0x004C
	bool BeingCollected; //0x0050
	char pad_0051[3]; //0x0051
	int Lifetime; //0x0054
	int ObjectType; //0x0058
	int MotionType; //0x005C
	int AttachmentID; //0x0060
	float CollectionDistance; //0x0064
	int SeedType; //0x0068
	char pad_006C[92]; //0x006C
	bool NeedsBouncyArrow; //0x00C8
	bool HasBouncyArrow; //0x00C9
	bool HitGround; //0x00CA
	char pad_00CB[1]; //0x00CB
	int TimesDropped; //0x00CC
}; //Size: 0x00D0