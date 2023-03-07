Literally remake Unity in C++?

High level view
Entity                  -   Contains a bunch of components, update, render

Graphics
SpriteRenderer          -   takes in a Sprite and shows it. That's all.
Sprite                  -   struct which contains all data needed to render a sprite to a screen, source position, source size

Animator                -   playAnimation(animation_name)   
Animation               -   a list of Sprites that will be shown to the screen

So SpriteRenderer and Animator can be somewhat decoupled. They both use Sprites, that's all.

Audio

Time
deltaTime               -   gets the delta time

Physics
BoxCollider2D
Rigidbody2D

FUCK EFFICIENCY! I am making 2D games. Make first, optimize later!