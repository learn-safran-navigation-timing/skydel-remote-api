#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the GPU index on which this spoofer signal will be modulated.
    ///
    /// Name     Type   Description
    /// -------- ------ -------------------------------
    /// GpuIdx   int    The GPU index.
    /// SignalId int    Spoofer output number, 0-based.
    /// Id       string Transmitter unique identifier.
    ///

    class SetSpoofTxGpuIdx;
    typedef std::shared_ptr<SetSpoofTxGpuIdx> SetSpoofTxGpuIdxPtr;
    
    
    class SetSpoofTxGpuIdx : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSpoofTxGpuIdx();

      SetSpoofTxGpuIdx(int gpuIdx, int signalId, const std::string& id);

      static SetSpoofTxGpuIdxPtr create(int gpuIdx, int signalId, const std::string& id);
      static SetSpoofTxGpuIdxPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** gpuIdx ****
      int gpuIdx() const;
      void setGpuIdx(int gpuIdx);


      // **** signalId ****
      int signalId() const;
      void setSignalId(int signalId);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

