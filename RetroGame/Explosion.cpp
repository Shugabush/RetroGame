#include "Explosion.h"

Explosion::Explosion() : SpriteObject()
{
	name = "Explosion";
	animationTimer = Timer(0.25f);
	sprites.push_back(enemyExplosionSprite);
	width = 25;
	height = 25;
}

void Explosion::UpdateAnimation()
{
	animationTimer.Update();
	if (animationTimer.PastTimer())
	{
		animationTimer.Reset();

		// Time to switch to the next sprite
		currentSprite++;
		if (currentSprite >= sprites.size())
		{
			currentSprite = 0;
			// We went through all the sprites, so destroy this object
			Destroy(this);
		}
	}
}

void Explosion::OnUpdate()
{
	UpdateAnimation();
	Update();
}