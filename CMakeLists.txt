cmake_minimum_required(VERSION 3.9)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Game_Music_Emu VERSION 0.7.0 DESCRIPTION "Game Music Emu Library")

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)
include(CheckIncludeFile)

find_package(ZLIB REQUIRED)
find_package(File_Extractor REQUIRED)

set(GAME_MUSIC_EMU_DEFINES
    HAVE_ZLIB_H=1
)
check_include_file(stdint.h HAVE_STDINT_H)
if(HAVE_STDINT_H)
    list(APPEND GAME_MUSIC_EMU_DEFINES HAVE_STDINT_H=1)
endif()

set(GAME_MUSIC_EMU_SOURCES
    gme/higan/dsp/SPC_DSP.cpp
    gme/higan/processor/spc700/spc700.cpp
    gme/higan/dsp/dsp.cpp
    gme/higan/smp/smp.cpp
    gme/Ay_Apu.cpp
    gme/Ay_Core.cpp
    gme/Ay_Cpu.cpp
    gme/Ay_Emu.cpp
    gme/Bml_Parser.cpp
    gme/blargg_common.cpp
    gme/blargg_errors.cpp
    gme/Blip_Buffer.cpp
    gme/Classic_Emu.cpp
    gme/Downsampler.cpp
    gme/Dual_Resampler.cpp
    gme/Effects_Buffer.cpp
    gme/Fir_Resampler.cpp
    gme/Gb_Apu.cpp
    gme/Gb_Cpu.cpp
    gme/Gb_Oscs.cpp
    gme/Gbs_Core.cpp
    gme/Gbs_Cpu.cpp
    gme/Gbs_Emu.cpp
    gme/gme.cpp
    gme/Gme_File.cpp
    gme/Gme_Loader.cpp
    gme/Gym_Emu.cpp
    gme/Hes_Apu.cpp
    gme/Hes_Apu_Adpcm.cpp
    gme/Hes_Core.cpp
    gme/Hes_Cpu.cpp
    gme/Hes_Emu.cpp
    gme/Kss_Core.cpp
    gme/Kss_Cpu.cpp
    gme/Kss_Emu.cpp
    gme/Kss_Scc_Apu.cpp
    gme/M3u_Playlist.cpp
    gme/Multi_Buffer.cpp
    gme/Music_Emu.cpp
    gme/Nes_Apu.cpp
    gme/Nes_Cpu.cpp
    gme/Nes_Fds_Apu.cpp
    gme/Nes_Fme7_Apu.cpp
    gme/Nes_Namco_Apu.cpp
    gme/Nes_Oscs.cpp
    gme/Nes_Vrc6_Apu.cpp
    gme/Nes_Vrc7_Apu.cpp
    gme/Nsf_Core.cpp
    gme/Nsf_Cpu.cpp
    gme/Nsf_Emu.cpp
    gme/Nsf_Impl.cpp
    gme/Nsfe_Emu.cpp
    gme/Opl_Apu.cpp
    gme/Resampler.cpp
    gme/Rom_Data.cpp
    gme/Sap_Apu.cpp
    gme/Sap_Core.cpp
    gme/Sap_Cpu.cpp
    gme/Sap_Emu.cpp
    gme/Sgc_Core.cpp
    gme/Sgc_Cpu.cpp
    gme/Sgc_Emu.cpp
    gme/Sgc_Impl.cpp
    gme/Sms_Apu.cpp
    gme/Sms_Fm_Apu.cpp
    gme/Spc_Emu.cpp
    gme/Spc_Filter.cpp
    gme/Spc_Sfm.cpp
    gme/Track_Filter.cpp
    gme/Upsampler.cpp
    gme/Vgm_Core.cpp
    gme/Vgm_Emu.cpp
    gme/Ym2413_Emu.cpp
    gme/Ym2612_Emu.cpp
    gme/Z80_Cpu.cpp
    vgmplay/VGMPlay/ChipMapper.c
    vgmplay/VGMPlay/chips/2151intf.c
    vgmplay/VGMPlay/chips/2203intf.c
    vgmplay/VGMPlay/chips/2413intf.c
    vgmplay/VGMPlay/chips/2608intf.c
    vgmplay/VGMPlay/chips/2610intf.c
    vgmplay/VGMPlay/chips/2612intf.c
    vgmplay/VGMPlay/chips/262intf.c
    vgmplay/VGMPlay/chips/3526intf.c
    vgmplay/VGMPlay/chips/3812intf.c
    vgmplay/VGMPlay/chips/8950intf.c
    vgmplay/VGMPlay/chips/adlibemu_opl2.c
    vgmplay/VGMPlay/chips/adlibemu_opl3.c
    vgmplay/VGMPlay/chips/ay8910.c
    vgmplay/VGMPlay/chips/ay_intf.c
    vgmplay/VGMPlay/chips/c140.c
    vgmplay/VGMPlay/chips/c352.c
    vgmplay/VGMPlay/chips/c6280.c
    vgmplay/VGMPlay/chips/c6280intf.c
    vgmplay/VGMPlay/chips/dac_control.c
    vgmplay/VGMPlay/chips/emu2149.c
    vgmplay/VGMPlay/chips/emu2413.c
    vgmplay/VGMPlay/chips/es5503.c
    vgmplay/VGMPlay/chips/es5506.c
    vgmplay/VGMPlay/chips/fm.c
    vgmplay/VGMPlay/chips/fm2612.c
    vgmplay/VGMPlay/chips/fmopl.c
    vgmplay/VGMPlay/chips/gb.c
    vgmplay/VGMPlay/chips/iremga20.c
    vgmplay/VGMPlay/chips/k051649.c
    vgmplay/VGMPlay/chips/k053260.c
    vgmplay/VGMPlay/chips/k054539.c
    vgmplay/VGMPlay/chips/multipcm.c
    vgmplay/VGMPlay/chips/nes_apu.c
    vgmplay/VGMPlay/chips/nes_intf.c
    vgmplay/VGMPlay/chips/np_nes_apu.c
    vgmplay/VGMPlay/chips/np_nes_dmc.c
    vgmplay/VGMPlay/chips/np_nes_fds.c
    vgmplay/VGMPlay/chips/okim6258.c
    vgmplay/VGMPlay/chips/okim6295.c
    vgmplay/VGMPlay/chips/Ootake_PSG.c
    vgmplay/VGMPlay/chips/panning.c
    vgmplay/VGMPlay/chips/pokey.c
    vgmplay/VGMPlay/chips/pwm.c
    vgmplay/VGMPlay/chips/qsound.c
    vgmplay/VGMPlay/chips/rf5c68.c
    vgmplay/VGMPlay/chips/saa1099.c
    vgmplay/VGMPlay/chips/scd_pcm.c
    vgmplay/VGMPlay/chips/scsp.c
    vgmplay/VGMPlay/chips/segapcm.c
    vgmplay/VGMPlay/chips/sn76489.c
    vgmplay/VGMPlay/chips/sn76496.c
    vgmplay/VGMPlay/chips/sn764intf.c
    vgmplay/VGMPlay/chips/upd7759.c
    vgmplay/VGMPlay/chips/vsu.c
    vgmplay/VGMPlay/chips/ws_audio.c
    vgmplay/VGMPlay/chips/x1_010.c
    vgmplay/VGMPlay/chips/yam.c
    vgmplay/VGMPlay/chips/ym2151.c
    vgmplay/VGMPlay/chips/ym2413.c
    vgmplay/VGMPlay/chips/ym2612.c
    vgmplay/VGMPlay/chips/ymdeltat.c
    vgmplay/VGMPlay/chips/ymf262.c
    vgmplay/VGMPlay/chips/ymf271.c
    vgmplay/VGMPlay/chips/ymf278b.c
    vgmplay/VGMPlay/chips/ymz280b.c
    vgmplay/VGMPlay/resampler.c
    vgmplay/VGMPlay/VGMPlay.c
)
set(GAME_MUSIC_EMU_HEADERS
    gme/adlib.h
    gme/Ay_Apu.h
    gme/Ay_Core.h
    gme/Ay_Emu.h
    gme/blargg_common.h
    gme/blargg_config.h
    gme/blargg_endian.h
    gme/blargg_errors.h
    gme/blargg_source.h
    gme/Blip_Buffer.h
    gme/Blip_Buffer_impl2.h
    gme/Blip_Buffer_impl.h
    gme/Bml_Parser.h
    gme/Classic_Emu.h
    gme/Downsampler.h
    gme/Dual_Resampler.h
    gme/Effects_Buffer.h
    gme/Fir_Resampler.h
    gme/Gb_Apu.h
    gme/Gb_Cpu.h
    gme/Gb_Cpu_run.h
    gme/Gb_Oscs.h
    gme/Gbs_Core.h
    gme/Gbs_Emu.h
    gme/gme_custom_dprintf.h
    gme/Gme_File.h
    gme/gme.h
    gme/Gme_Loader.h
    gme/Gym_Emu.h
    gme/Hes_Apu_Adpcm.h
    gme/Hes_Apu.h
    gme/Hes_Core.h
    gme/Hes_Cpu.h
    gme/Hes_Cpu_run.h
    gme/Hes_Emu.h
    gme/higan/dsp/dsp.hpp
    gme/higan/dsp/SPC_DSP.h
    gme/higan/processor/spc700/memory.hpp
    gme/higan/processor/spc700/registers.hpp
    gme/higan/processor/spc700/spc700.hpp
    gme/higan/smp/smp.hpp
    gme/Kss_Core.h
    gme/Kss_Emu.h
    gme/Kss_Scc_Apu.h
    gme/M3u_Playlist.h
    gme/Multi_Buffer.h
    gme/Music_Emu.h
    gme/Nes_Apu.h
    gme/Nes_Cpu.h
    gme/Nes_Cpu_run.h
    gme/Nes_Fds_Apu.h
    gme/Nes_Fme7_Apu.h
    gme/Nes_Mmc5_Apu.h
    gme/Nes_Namco_Apu.h
    gme/Nes_Oscs.h
    gme/Nes_Vrc6_Apu.h
    gme/Nes_Vrc7_Apu.h
    gme/Nsf_Core.h
    gme/Nsfe_Emu.h
    gme/Nsf_Emu.h
    gme/Nsf_Impl.h
    gme/Opl_Apu.h
    gme/Resampler.h
    gme/Rom_Data.h
    gme/Sap_Apu.h
    gme/Sap_Core.h
    gme/Sap_Emu.h
    gme/Sgc_Core.h
    gme/Sgc_Emu.h
    gme/Sgc_Impl.h
    gme/Sms_Apu.h
    gme/Sms_Fm_Apu.h
    gme/Spc_Emu.h
    gme/Spc_Filter.h
    gme/Spc_Sfm.h
    gme/Track_Filter.h
    gme/Upsampler.h
    gme/Vgm_Core.h
    gme/Vgm_Emu.h
    gme/Ym2413_Emu.h
    gme/Ym2612_Emu.h
    gme/Z80_Cpu.h
    gme/Z80_Cpu_run.h
)

add_library(gme ${GAME_MUSIC_EMU_SOURCES})
set_target_properties(gme PROPERTIES POSITION_INDEPENDENT_CODE 1)
target_compile_definitions(gme PRIVATE ${GAME_MUSIC_EMU_DEFINES})
target_include_directories(gme PRIVATE ${PROJECT_SOURCE_DIR}/gme)

set_target_properties(gme PROPERTIES VERSION ${PROJECT_VERSION})

target_include_directories(gme PUBLIC
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/gme>
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/gme>
)

target_link_libraries(gme PRIVATE File_Extractor::fex ZLIB::ZLIB)

install(TARGETS gme
  EXPORT gme-targets
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(EXPORT gme-targets
  FILE
    "Game_Music_EmuTargets.cmake"
  NAMESPACE
    "Game_Music_Emu::"
  DESTINATION
    "${CMAKE_INSTALL_LIBDIR}/cmake/Game_Music_Emu"
)

write_basic_package_version_file(
    "${PROJECT_BINARY_DIR}/Game_Music_EmuConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(
    "${PROJECT_SOURCE_DIR}/cmake/Game_Music_EmuConfig.cmake.in"
    "${PROJECT_BINARY_DIR}/Game_Music_EmuConfig.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/Game_Music_Emu"
)

install(FILES
    "${PROJECT_BINARY_DIR}/Game_Music_EmuConfig.cmake"
    "${PROJECT_BINARY_DIR}/Game_Music_EmuConfigVersion.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/Game_Music_Emu"
)

configure_file(
    "${PROJECT_SOURCE_DIR}/cmake/libgme.pc.in"
    "${PROJECT_BINARY_DIR}/libgme.pc"
    @ONLY
)

install(FILES
    "${PROJECT_BINARY_DIR}/libgme.pc"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/pkgconfig"
)

export(TARGETS gme
    FILE "${PROJECT_BINARY_DIR}/Game_Music_EmuTargets.cmake"
    NAMESPACE "Game_Music_Emu::"
)
export(PACKAGE Game_Music_Emu)

install(FILES ${GAME_MUSIC_EMU_HEADERS} DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/gme)

