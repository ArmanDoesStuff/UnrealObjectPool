# Unreal Object Pool

Simple, efficient, and easy to use. With this Unreal Object Pool, you can easily replace any calls to `SpawnActor` with the new ActorPool subsystem's `GetActor` and save on processing power by reusing old actors.

### How to Use

1. **Create a Poolable Actor**  
   Create a `PoolableActor` (it will throw an error if there is no primitive component at the root).     
![Blueprint Creation](https://i0.wp.com/www.armandoesstuff.com/wp-content/uploads/2025/04/image.png)
3. **Get Actor from pool**  
   Access the `Actor Pool` subsystem from anywhere to call `GetActor`. If there is a waiting actor it will activate it, if not, it will spawn one.     
![Get Actor method](https://i0.wp.com/www.armandoesstuff.com/wp-content/uploads/2025/04/image-1.png)
4. **Reset Actor with OnActorGet**  
   A new `OnActorGet` event is available to replace `BeginPlay`. Use this to reset any changes that may have been made to the actor before deactivating.    
![OnActorGet and Release](https://i0.wp.com/www.armandoesstuff.com/wp-content/uploads/2025/04/image-2.png)
5. **Release Actor to the Pool**  
   Instead of destroying it, call `Release` to return it to the `ActorPool`, making it ready for the next time you call `GetActor`.
