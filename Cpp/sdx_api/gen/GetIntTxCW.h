#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get informations about the CW signal of the transmitter.
    ///
    /// Name          Type   Description
    /// ------------- ------ ------------------------------
    /// TransmitterId string Transmitter unique identifier.
    /// SignalId      string CW unique identifier.
    ///

    class GetIntTxCW;
    typedef std::shared_ptr<GetIntTxCW> GetIntTxCWPtr;
    
    
    class GetIntTxCW : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetIntTxCW();

      GetIntTxCW(const std::string& transmitterId, const std::string& signalId);

      static GetIntTxCWPtr create(const std::string& transmitterId, const std::string& signalId);
      static GetIntTxCWPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

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

