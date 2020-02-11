cmake_minimum_required(VERSION 3.5)

project(r-type LANGUAGES CXX)

# Set c++ version
set(CMAKE_CXX_STANDARD 17)

# Conan
include(build/conanbuildinfo.cmake)
conan_basic_setup()

# Components
set(COMPONENTS
  Server/Game/Components/src/Life.cpp
  Server/Game/Components/src/Damage.cpp
  Server/Game/Components/src/Drawable.cpp
  Server/Game/Components/src/Texture.cpp
  Server/Game/Components/src/AVector.cpp
  Server/Game/Components/src/Transform.cpp
  Server/Game/Components/src/Speed.cpp
  Server/Game/Components/src/Player.cpp
  Server/Game/Components/src/Position.cpp
  Server/Game/Components/src/Size.cpp
  Server/Game/Components/src/Enemy.cpp
)

# Systems
set(SYSTEMS
  Server/Game/Systems/src/ApplyDamages.cpp
  Server/Game/Systems/src/ApplyMovement.cpp
  Server/Game/Systems/src/UpdateAnimation.cpp
  Server/Game/Systems/src/Draw.cpp
  Server/Game/Systems/src/DrawLife.cpp
  Server/Game/Systems/src/EntityKiller.cpp
  Server/Game/Systems/src/Colidable.cpp
)

# Server
add_executable(r-type_server
  # Sources
  ${COMPONENTS}
  ${SYSTEMS}
  Server/main.cpp
  Server/Engine/src/Id.cpp
  Server/Engine/src/World.cpp
  Server/Engine/src/NetworkPack.cpp
  Server/Engine/src/Entity.cpp
  Server/Engine/src/ASystem.cpp
  Server/Engine/src/Byte.cpp
  Server/Game/Systems/src/ApplyDamages.cpp
  Server/Game/Systems/src/ApplyMovement.cpp
  Server/Game/src/Game.cpp
  Server/Game/src/GameHandler.cpp
  Server/Game/src/GameServer.cpp
  Server/Game/src/EngineSrv.cpp
  Server/Network/src/BoostUdp.cpp
  Server/Network/src/BoostServer.cpp
  Client/Core/src/GameComponents.cpp
  Client/Core/src/GameSystems.cpp
)

target_include_directories(r-type_server PUBLIC
  # Include directories
  Server
  Server/Engine/include
  Server/Game/include
  Server/Game/Components/include
  Server/Game/Systems/include
  Server/Network/include
  Client/Core/include
)

target_link_libraries(r-type_server PRIVATE ${CONAN_LIBS})

# Client
add_executable(r-type_client
  # Sources
  ${COMPONENTS}
  ${SYSTEMS}
  Client/main.cpp
  Client/Core/src/ClientListener.cpp
  Client/Core/src/Core.cpp
  Client/Core/src/EngineCli.cpp
  Client/Core/src/AEngine.cpp
  Client/Core/src/CoreHandler.cpp
  Server/Network/src/BoostUdp.cpp
  Server/Network/src/BoostServer.cpp
  Server/Engine/src/Id.cpp
  Server/Engine/src/World.cpp
  Server/Engine/src/NetworkPack.cpp
  Server/Engine/src/Entity.cpp
  Client/Core/src/GameComponents.cpp
  Client/Core/src/GameSystems.cpp
  Server/Engine/src/ASystem.cpp
  Server/Engine/src/Byte.cpp
)

target_include_directories(r-type_client PUBLIC
  # Include directories
  Server/Network/include
  Server/Engine/include
  Client/Core/include
  Server/Game/Components/include
  Server/Game/Systems/include
)

target_link_libraries(r-type_client PRIVATE ${CONAN_LIBS})
