/* (c) Magnus Auvinen. See licence.txt in the root of the distribution for more information. */
/* If you are missing that file, acquire a complete release at teeworlds.com.                */
#ifndef GAME_COLLISION_H
#define GAME_COLLISION_H

#include <base/vmath.h>

class CCollision
{
	class CTile *m_pTiles;
	class CTile *m_pTeleTiles;

	vec2 m_aTeleTargets[256];

	int m_Width;
	int m_Height;
	class CLayers *m_pLayers;

	bool IsTileSolid(int x, int y);
	int GetTile(int x, int y);

public:
	enum
	{
		COLFLAG_SOLID=1,
		COLFLAG_DEATH=2,
		COLFLAG_NOHOOK=4,

		TELEFLAG_IN=1,
		TELEFLAG_RESET_VEL=2,
		TELEFLAG_CUT_OTHER=4,
		TELEFLAG_CUT_OWN=8,

		TRIGGERFLAG_CUT_OTHER=1,
		TRIGGERFLAG_CUT_OWN=2,

	};

	CCollision();
	void Init(class CLayers *pLayers);
	bool CheckPoint(float x, float y) { return IsTileSolid(round(x), round(y)); }
	bool CheckPoint(vec2 Pos) { return CheckPoint(Pos.x, Pos.y); }
	int GetCollisionAt(float x, float y) { return GetTile(round(x), round(y)); }
	bool Teleport(vec2 *pInoutPos, bool *pOutResetVel, bool *pOutCutOther, bool *pOutCutOwn);
	int GetWidth() { return m_Width; };
	int GetHeight() { return m_Height; };
	int IntersectLine(vec2 Pos0, vec2 Pos1, vec2 *pOutCollision, vec2 *pOutBeforeCollision);
	void MovePoint(vec2 *pInoutPos, vec2 *pInoutVel, float Elasticity, int *pBounces);
	int MoveBox(vec2 *pInoutPos, vec2 *pInoutVel, vec2 Size, float Elasticity);
	void HandleTriggerTiles(int Index, int *TriggerFlags);
	bool TestBox(vec2 Pos, vec2 Size);
};

#endif
