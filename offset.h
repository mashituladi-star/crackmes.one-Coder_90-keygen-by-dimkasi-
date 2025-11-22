#pragma once

namespace KeygenOffsets {

    // Core functions
    namespace Functions {
        constexpr uintptr_t MainWindowProc    = 0x1A40;
        constexpr uintptr_t AboutWindowProc   = 0x16B0;
        constexpr uintptr_t HashAlgorithm     = 0x1610;
        constexpr uintptr_t InitializeApp     = 0x1140;
        constexpr uintptr_t WinMain           = 0x1E70;
    }

    // String resources
    namespace Strings {
        constexpr uintptr_t ClassName         = 0x514F;  // "KGCLASS_SIMPLE"
        constexpr uintptr_t AboutClass        = 0x51A9;  // "AboutWndClass"
        constexpr uintptr_t WindowTitle       = 0x5161;  // "KeygenMe"
        constexpr uintptr_t NameLabel         = 0x5156;  // "Name:"
        constexpr uintptr_t KeyLabel          = 0x5162;  // "Key:"
        constexpr uintptr_t CheckButton       = 0x516E;  // "CHECK KEY"
        constexpr uintptr_t AboutButton       = 0x5178;  // "About"
        constexpr uintptr_t SuccessMessage    = 0x517E;  // "Access Granted!"
        constexpr uintptr_t FailedMessage     = 0x5196;  // "Invalid Key"
    }

    // Global variables
    namespace Globals {
        constexpr uintptr_t NameEditHandle    = 0x37EF50;
        constexpr uintptr_t KeyEditHandle     = 0x37EF58;
        constexpr uintptr_t AboutFont         = 0x37F290;
        constexpr uintptr_t WindowWidth       = 0x37F284;
        constexpr uintptr_t WindowHeight      = 0x37F288;
        constexpr uintptr_t ScrollPosition    = 0x37F280;
        constexpr uintptr_t StarPositions     = 0x37EF60; // 100 stars: X,Y pairs
    }

    // Algorithm constants
    namespace Algorithm {
        constexpr uint32_t Magic1             = 0x55555555;
        constexpr uint32_t Magic2             = 0xDEADC0DE;
        constexpr uint32_t Constant1          = 0x90F01234;
        constexpr uint32_t Constant2          = 0xE5D4C3B3;
        constexpr int StarCount               = 100;
    }

    // UI constants
    namespace UI {
        constexpr uint32_t MainWindowStyle    = 0x10CA0000;
        constexpr uint32_t AboutWindowStyle   = 0x90C80000;
        constexpr int MainWidth               = 350;     // 0x15E
        constexpr int MainHeight              = 190;     // 0xBE
        constexpr int AboutWidth              = 300;     // 0x12C
        constexpr int AboutHeight             = 250;     // 0xFA
        
        constexpr uint32_t StaticStyle        = 0x50000000;
        constexpr uint32_t EditStyle          = 0x50800080;
        constexpr uint32_t ButtonStyle        = 0x50000001;
        
        constexpr int NameEditID              = 0x3;
        constexpr int KeyEditID               = 0x0;
        constexpr int CheckButtonID           = 0x1;
        constexpr int AboutButtonID           = 0x2;
    }

    // Resources
    namespace Resources {
        constexpr uint32_t SuccessIcon        = 0x40;    // MB_ICONINFORMATION
        constexpr uint32_t FailedIcon         = 0x10;    // MB_ICONERROR
        constexpr uintptr_t AboutSound        = 0x7000;
        constexpr int TimerID                 = 0x1;
        constexpr int TimerInterval           = 0x1E;    // 30ms
    }
}