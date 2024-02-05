// SPDX-License-Identifier: Apache-2.0

#pragma once

#include <scratchcpp/iblocksection.h>

namespace libscratchcpp
{

class Compiler;
class VirtualMachine;

/*! \brief The EventBlocks class contains the implementation of event blocks. */
class EventBlocks : public IBlockSection
{
    public:
        enum Inputs
        {
            BROADCAST_INPUT
        };

        enum Fields
        {
            BROADCAST_OPTION,
            BACKDROP,
            KEY_OPTION
        };

        std::string name() const override;

        void registerBlocks(IEngine *engine) override;

        static void compileWhenFlagClicked(Compiler *compiler);
        static void compileWhenThisSpriteClicked(Compiler *compiler);
        static void compileWhenStageClicked(Compiler *compiler);
        static void compileBroadcast(Compiler *compiler);
        static void compileBroadcastAndWait(Compiler *compiler);
        static void compileWhenBroadcastReceived(Compiler *compiler);
        static void compileWhenBackdropSwitchesTo(Compiler *compiler);
        static void compileWhenKeyPressed(Compiler *compiler);

        static unsigned int broadcast(VirtualMachine *vm);
        static unsigned int broadcastByIndex(VirtualMachine *vm);
        static unsigned int broadcastAndWait(VirtualMachine *vm);
        static unsigned int broadcastByIndexAndWait(VirtualMachine *vm);
        static unsigned int checkBroadcast(VirtualMachine *vm);
        static unsigned int checkBroadcastByIndex(VirtualMachine *vm);
};

} // namespace libscratchcpp
