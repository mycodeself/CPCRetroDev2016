##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=psychicstest
ConfigurationName      :=Debug
WorkspacePath          := "/home/user/cpctelera/projects/psychicstest"
ProjectPath            := "/home/user/cpctelera/projects/psychicstest"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=user
Date                   :=23/09/16
CodeLitePath           :="/home/user/.codelite"
LinkerName             :=/usr/bin/x86_64-linux-gnu-g++
SharedObjectLinkerName :=/usr/bin/x86_64-linux-gnu-g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="psychicstest.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -O0
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)/home/user/cpctelera/cpctelera $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch). $(LibraryPathSwitch)Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/x86_64-linux-gnu-ar rcu
CXX      := /usr/bin/x86_64-linux-gnu-g++
CC       := /usr/bin/x86_64-linux-gnu-gcc
CXXFLAGS :=  -g -Wall $(Preprocessors)
CFLAGS   :=   $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/x86_64-linux-gnu-as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/src_main.c$(ObjectSuffix) $(IntermediateDirectory)/src_game.c$(ObjectSuffix) $(IntermediateDirectory)/character_character.c$(ObjectSuffix) $(IntermediateDirectory)/draw_draw.c$(ObjectSuffix) $(IntermediateDirectory)/assets_level0.c$(ObjectSuffix) $(IntermediateDirectory)/assets_assets.c$(ObjectSuffix) $(IntermediateDirectory)/assets_level0_tileset.c$(ObjectSuffix) $(IntermediateDirectory)/animations_animations.c$(ObjectSuffix) $(IntermediateDirectory)/physics_physics.c$(ObjectSuffix) $(IntermediateDirectory)/utils_utils.c$(ObjectSuffix) \
	$(IntermediateDirectory)/level0_level0.c$(ObjectSuffix) $(IntermediateDirectory)/level0_level0_map.c$(ObjectSuffix) $(IntermediateDirectory)/level0_level0_tileset.c$(ObjectSuffix) $(IntermediateDirectory)/sprites_walk1.c$(ObjectSuffix) $(IntermediateDirectory)/sprites_idle.c$(ObjectSuffix) $(IntermediateDirectory)/sprites_walk0.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_main.c$(ObjectSuffix): src/main.c $(IntermediateDirectory)/src_main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/user/cpctelera/projects/psychicstest/src/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_main.c$(DependSuffix): src/main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_main.c$(DependSuffix) -MM "src/main.c"

$(IntermediateDirectory)/src_main.c$(PreprocessSuffix): src/main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_main.c$(PreprocessSuffix) "src/main.c"

$(IntermediateDirectory)/src_game.c$(ObjectSuffix): src/game.c $(IntermediateDirectory)/src_game.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/user/cpctelera/projects/psychicstest/src/game.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_game.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_game.c$(DependSuffix): src/game.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_game.c$(ObjectSuffix) -MF$(IntermediateDirectory)/src_game.c$(DependSuffix) -MM "src/game.c"

$(IntermediateDirectory)/src_game.c$(PreprocessSuffix): src/game.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_game.c$(PreprocessSuffix) "src/game.c"

$(IntermediateDirectory)/character_character.c$(ObjectSuffix): src/character/character.c $(IntermediateDirectory)/character_character.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/user/cpctelera/projects/psychicstest/src/character/character.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/character_character.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/character_character.c$(DependSuffix): src/character/character.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/character_character.c$(ObjectSuffix) -MF$(IntermediateDirectory)/character_character.c$(DependSuffix) -MM "src/character/character.c"

$(IntermediateDirectory)/character_character.c$(PreprocessSuffix): src/character/character.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/character_character.c$(PreprocessSuffix) "src/character/character.c"

$(IntermediateDirectory)/draw_draw.c$(ObjectSuffix): src/draw/draw.c $(IntermediateDirectory)/draw_draw.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/user/cpctelera/projects/psychicstest/src/draw/draw.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/draw_draw.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/draw_draw.c$(DependSuffix): src/draw/draw.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/draw_draw.c$(ObjectSuffix) -MF$(IntermediateDirectory)/draw_draw.c$(DependSuffix) -MM "src/draw/draw.c"

$(IntermediateDirectory)/draw_draw.c$(PreprocessSuffix): src/draw/draw.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/draw_draw.c$(PreprocessSuffix) "src/draw/draw.c"

$(IntermediateDirectory)/assets_level0.c$(ObjectSuffix): src/assets/level0.c $(IntermediateDirectory)/assets_level0.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/user/cpctelera/projects/psychicstest/src/assets/level0.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/assets_level0.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/assets_level0.c$(DependSuffix): src/assets/level0.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/assets_level0.c$(ObjectSuffix) -MF$(IntermediateDirectory)/assets_level0.c$(DependSuffix) -MM "src/assets/level0.c"

$(IntermediateDirectory)/assets_level0.c$(PreprocessSuffix): src/assets/level0.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/assets_level0.c$(PreprocessSuffix) "src/assets/level0.c"

$(IntermediateDirectory)/assets_assets.c$(ObjectSuffix): src/assets/assets.c $(IntermediateDirectory)/assets_assets.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/user/cpctelera/projects/psychicstest/src/assets/assets.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/assets_assets.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/assets_assets.c$(DependSuffix): src/assets/assets.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/assets_assets.c$(ObjectSuffix) -MF$(IntermediateDirectory)/assets_assets.c$(DependSuffix) -MM "src/assets/assets.c"

$(IntermediateDirectory)/assets_assets.c$(PreprocessSuffix): src/assets/assets.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/assets_assets.c$(PreprocessSuffix) "src/assets/assets.c"

$(IntermediateDirectory)/assets_level0_tileset.c$(ObjectSuffix): src/assets/level0_tileset.c $(IntermediateDirectory)/assets_level0_tileset.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/user/cpctelera/projects/psychicstest/src/assets/level0_tileset.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/assets_level0_tileset.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/assets_level0_tileset.c$(DependSuffix): src/assets/level0_tileset.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/assets_level0_tileset.c$(ObjectSuffix) -MF$(IntermediateDirectory)/assets_level0_tileset.c$(DependSuffix) -MM "src/assets/level0_tileset.c"

$(IntermediateDirectory)/assets_level0_tileset.c$(PreprocessSuffix): src/assets/level0_tileset.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/assets_level0_tileset.c$(PreprocessSuffix) "src/assets/level0_tileset.c"

$(IntermediateDirectory)/animations_animations.c$(ObjectSuffix): src/animations/animations.c $(IntermediateDirectory)/animations_animations.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/user/cpctelera/projects/psychicstest/src/animations/animations.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/animations_animations.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/animations_animations.c$(DependSuffix): src/animations/animations.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/animations_animations.c$(ObjectSuffix) -MF$(IntermediateDirectory)/animations_animations.c$(DependSuffix) -MM "src/animations/animations.c"

$(IntermediateDirectory)/animations_animations.c$(PreprocessSuffix): src/animations/animations.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/animations_animations.c$(PreprocessSuffix) "src/animations/animations.c"

$(IntermediateDirectory)/physics_physics.c$(ObjectSuffix): src/physics/physics.c $(IntermediateDirectory)/physics_physics.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/user/cpctelera/projects/psychicstest/src/physics/physics.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/physics_physics.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/physics_physics.c$(DependSuffix): src/physics/physics.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/physics_physics.c$(ObjectSuffix) -MF$(IntermediateDirectory)/physics_physics.c$(DependSuffix) -MM "src/physics/physics.c"

$(IntermediateDirectory)/physics_physics.c$(PreprocessSuffix): src/physics/physics.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/physics_physics.c$(PreprocessSuffix) "src/physics/physics.c"

$(IntermediateDirectory)/utils_utils.c$(ObjectSuffix): src/utils/utils.c $(IntermediateDirectory)/utils_utils.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/user/cpctelera/projects/psychicstest/src/utils/utils.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/utils_utils.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/utils_utils.c$(DependSuffix): src/utils/utils.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/utils_utils.c$(ObjectSuffix) -MF$(IntermediateDirectory)/utils_utils.c$(DependSuffix) -MM "src/utils/utils.c"

$(IntermediateDirectory)/utils_utils.c$(PreprocessSuffix): src/utils/utils.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/utils_utils.c$(PreprocessSuffix) "src/utils/utils.c"

$(IntermediateDirectory)/level0_level0.c$(ObjectSuffix): src/levels/level0/level0.c $(IntermediateDirectory)/level0_level0.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/user/cpctelera/projects/psychicstest/src/levels/level0/level0.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/level0_level0.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/level0_level0.c$(DependSuffix): src/levels/level0/level0.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/level0_level0.c$(ObjectSuffix) -MF$(IntermediateDirectory)/level0_level0.c$(DependSuffix) -MM "src/levels/level0/level0.c"

$(IntermediateDirectory)/level0_level0.c$(PreprocessSuffix): src/levels/level0/level0.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/level0_level0.c$(PreprocessSuffix) "src/levels/level0/level0.c"

$(IntermediateDirectory)/level0_level0_map.c$(ObjectSuffix): src/levels/level0/level0_map.c $(IntermediateDirectory)/level0_level0_map.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/user/cpctelera/projects/psychicstest/src/levels/level0/level0_map.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/level0_level0_map.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/level0_level0_map.c$(DependSuffix): src/levels/level0/level0_map.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/level0_level0_map.c$(ObjectSuffix) -MF$(IntermediateDirectory)/level0_level0_map.c$(DependSuffix) -MM "src/levels/level0/level0_map.c"

$(IntermediateDirectory)/level0_level0_map.c$(PreprocessSuffix): src/levels/level0/level0_map.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/level0_level0_map.c$(PreprocessSuffix) "src/levels/level0/level0_map.c"

$(IntermediateDirectory)/level0_level0_tileset.c$(ObjectSuffix): src/levels/level0/level0_tileset.c $(IntermediateDirectory)/level0_level0_tileset.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/user/cpctelera/projects/psychicstest/src/levels/level0/level0_tileset.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/level0_level0_tileset.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/level0_level0_tileset.c$(DependSuffix): src/levels/level0/level0_tileset.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/level0_level0_tileset.c$(ObjectSuffix) -MF$(IntermediateDirectory)/level0_level0_tileset.c$(DependSuffix) -MM "src/levels/level0/level0_tileset.c"

$(IntermediateDirectory)/level0_level0_tileset.c$(PreprocessSuffix): src/levels/level0/level0_tileset.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/level0_level0_tileset.c$(PreprocessSuffix) "src/levels/level0/level0_tileset.c"

$(IntermediateDirectory)/sprites_walk1.c$(ObjectSuffix): src/character/sprites/walk1.c $(IntermediateDirectory)/sprites_walk1.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/user/cpctelera/projects/psychicstest/src/character/sprites/walk1.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sprites_walk1.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sprites_walk1.c$(DependSuffix): src/character/sprites/walk1.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sprites_walk1.c$(ObjectSuffix) -MF$(IntermediateDirectory)/sprites_walk1.c$(DependSuffix) -MM "src/character/sprites/walk1.c"

$(IntermediateDirectory)/sprites_walk1.c$(PreprocessSuffix): src/character/sprites/walk1.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sprites_walk1.c$(PreprocessSuffix) "src/character/sprites/walk1.c"

$(IntermediateDirectory)/sprites_idle.c$(ObjectSuffix): src/character/sprites/idle.c $(IntermediateDirectory)/sprites_idle.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/user/cpctelera/projects/psychicstest/src/character/sprites/idle.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sprites_idle.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sprites_idle.c$(DependSuffix): src/character/sprites/idle.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sprites_idle.c$(ObjectSuffix) -MF$(IntermediateDirectory)/sprites_idle.c$(DependSuffix) -MM "src/character/sprites/idle.c"

$(IntermediateDirectory)/sprites_idle.c$(PreprocessSuffix): src/character/sprites/idle.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sprites_idle.c$(PreprocessSuffix) "src/character/sprites/idle.c"

$(IntermediateDirectory)/sprites_walk0.c$(ObjectSuffix): src/character/sprites/walk0.c $(IntermediateDirectory)/sprites_walk0.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/user/cpctelera/projects/psychicstest/src/character/sprites/walk0.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/sprites_walk0.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/sprites_walk0.c$(DependSuffix): src/character/sprites/walk0.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/sprites_walk0.c$(ObjectSuffix) -MF$(IntermediateDirectory)/sprites_walk0.c$(DependSuffix) -MM "src/character/sprites/walk0.c"

$(IntermediateDirectory)/sprites_walk0.c$(PreprocessSuffix): src/character/sprites/walk0.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/sprites_walk0.c$(PreprocessSuffix) "src/character/sprites/walk0.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


