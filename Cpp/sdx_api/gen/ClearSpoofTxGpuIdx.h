#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Reset the spoofer's signal GPU index to default.
    ///
    /// Name     Type   Description
    /// -------- ------ -------------------------------
    /// SignalId int    Spoofer output number, 0-based.
    /// Id       string Transmitter unique identifier.
    ///

    class ClearSpoofTxGpuIdx;
    typedef std::shared_ptr<ClearSpoofTxGpuIdx> ClearSpoofTxGpuIdxPtr;
    
    
    class ClearSpoofTxGpuIdx : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      ClearSpoofTxGpuIdx();

      ClearSpoofTxGpuIdx(int signalId, const std::string& id);

      static ClearSpoofTxGpuIdxPtr create(int signalId, const std::string& id);
      static ClearSpoofTxGpuIdxPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** signalId ****
      int signalId() const;
      void setSignalId(int signalId);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

