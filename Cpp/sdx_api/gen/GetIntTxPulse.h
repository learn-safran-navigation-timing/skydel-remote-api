#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get pulse signal interference.
    ///
    /// Name          Type   Description
    /// ------------- ------ ------------------------------
    /// TransmitterId string Transmitter unique identifier.
    /// SignalId      string Pulse unique identifier.
    ///

    class GetIntTxPulse;
    typedef std::shared_ptr<GetIntTxPulse> GetIntTxPulsePtr;
    
    
    class GetIntTxPulse : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIntTxPulse();

      GetIntTxPulse(const std::string& transmitterId, const std::string& signalId);

      static GetIntTxPulsePtr create(const std::string& transmitterId, const std::string& signalId);
      static GetIntTxPulsePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** transmitterId ****
      std::string transmitterId() const;
      void setTransmitterId(const std::string& transmitterId);


      // **** signalId ****
      std::string signalId() const;
      void setSignalId(const std::string& signalId);
    };
    
  }
}

