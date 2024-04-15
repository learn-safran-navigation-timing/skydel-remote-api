#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Change whether a signal is enabled or disabled
    ///
    /// Name          Type   Description
    /// ------------- ------ ------------------------------------
    /// Enabled       bool   Whether the signal is enabled or not
    /// TransmitterId string Transmitter unique identifier.
    /// SignalId      string CW unique identifier.
    ///

    class EnableIntTxSignal;
    typedef std::shared_ptr<EnableIntTxSignal> EnableIntTxSignalPtr;
    
    
    class EnableIntTxSignal : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      EnableIntTxSignal();

      EnableIntTxSignal(bool enabled, const std::string& transmitterId, const std::string& signalId);

      static EnableIntTxSignalPtr create(bool enabled, const std::string& transmitterId, const std::string& signalId);
      static EnableIntTxSignalPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);


      // **** transmitterId ****
      std::string transmitterId() const;
      void setTransmitterId(const std::string& transmitterId);


      // **** signalId ****
      std::string signalId() const;
      void setSignalId(const std::string& signalId);
    };
    
  }
}

