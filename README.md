# SuperSpring22
Project for csci 39541 Game Engines
# Unique to Project
- Input handling uses array of bool
- Collisions is moved to entity and separated into two methods
- Jump speed and gravity is calculated based on desired jump height
- Turned game into a platformer
- Added struct with collision information to tell if player is standing on a platform
- Added game map class to generate map from a file
- The game automatically switches levels when you reach the goal

## Input handling
I used an array `Keys[349]` in `SpringApp` to tell if a key was being pressed
```cpp
SetKeyPressedCallback([this](const TDE::KeyPressedEvent& e) {
	if (e.GetKeyCode() >= 0 and e.GetKeyCode() < 349)
		Keys[e.GetKeyCode()] = true;
});

SetKeyReleasedCallback([this](const TDE::KeyReleasedEvent& e) {
	if (e.GetKeyCode() >= 0 and e.GetKeyCode() < 349)
		Keys[e.GetKeyCode()] = false;
});
```
## Collisions
- Moved Collisions to Entity
- Split Collisions function into Vertical and Horizontal function
## Physics
### Jump Physics
$v_0$ - initial velocity
$g$ - gravity
$t$ - time
$f(t)$ - current velocity
$$f(t) = -gt \times v_0$$
```cpp
mJumpSpeed = (2 * mJumpHeight) / mTimeToApex;
```
### Gravity
Calculated how string gravity should be based off of desired jump height
$t_h$ - time to reach the desired height
$h$ - desired jump height ($f(t_h) = h$)
$v_0$ - initial velocity ($v_0=-gt_h$)
$g$ - gravity
$p_0$ - starting position ($0$)
$$v_0=\frac{2h}{t_h}$$
```cpp
mGravity = (-2 * mJumpHeight) / (mTimeToApex * mTimeToApex);
```
## Added Collision info 
```cpp
struct CollisionInfo {
	bool left, right;
	bool above, below;

	void Reset() {
		left = right = false;
		above = below = false;
	}
};
```
Used it to prevent a player from jumping in the air
```cpp
if (Keys[TDE_KEY_SPACE] and mPlayer.collisions.below)
		yVelocity = 13;
```
## Game Map
Every tile is 100px, 100px
The position of the tile is based of the row and column
```cpp
tile.SetX(col * 100);
tile.SetY(row * 100);
```
So a tile at index `[0][0]` will be placed at position `(0,0)` \
And a tile at index `[2][3]` will be placed at position `(200,300)`