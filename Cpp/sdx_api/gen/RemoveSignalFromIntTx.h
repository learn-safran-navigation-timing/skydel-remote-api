#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Removes the specified signal from the interference transmitter.
    ///
    /// Name          Type   Description
    /// ------------- ------ ------------------------------
    /// TransmitterId string Transmitter unique identifier.
    /// SignalId      string Signal unique identifier.
    ///

    class RemoveSignalFromIntTx;
    typedef std::shared_ptr<RemoveSignalFromIntTx> RemoveSignalFromIntTxPtr;
    
    
    class RemoveSignalFromIntTx : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      RemoveSignalFromIntTx();

      RemoveSignalFromIntTx(const std::string& transmitterId, const std::string& signalId);

      static RemoveSignalFromIntTxPtr create(const std::string& transmitterId, const std::string& signalId);
      static RemoveSignalFromIntTxPtr dynamicCast(CommandBasePtr ptr);
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

