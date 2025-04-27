# Unreal Actor Pool

Simple, efficient, and easy to use. With this Unreal Object Pool, you can easily replace any calls to `SpawnActor` with the new ActorPool subsystem's `GetActor` and save on processing power by reusing old actors.

### How to Use

1. **Create a Poolable Actor**  
   Create a `PoolableActor`. The root should be a primitive component but it should work, regardless.    
![Blueprint Creation](https://i0.wp.com/www.armandoesstuff.com/wp-content/uploads/2025/04/image.png)
3. **Get Actor from pool**  
   Call `GetPoolableActor`. If there is a waiting `PoolableActor` it will activate it, if not, it will spawn one.
![Get Actor method](https://i0.wp.com/www.armandoesstuff.com/wp-content/uploads/2025/04/image-5.png))
4. **Reset Actor with OnActorGet**  
   A new `OnActorGet` event is available to replace `BeginPlay`. Use this to reset any changes that may have been made to the actor before deactivating.    
![OnActorGet and Release](https://i0.wp.com/www.armandoesstuff.com/wp-content/uploads/2025/04/image-2.png)
5. **Release Actor to the Pool**  
   Instead of destroying it, call `Release` to return it to the `ActorPool`, making it ready for the next time you call `GetActor`.
