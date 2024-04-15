#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Removes all signals from the interference transmitter.
    ///
    /// Name          Type   Description
    /// ------------- ------ ------------------------------
    /// TransmitterId string Transmitter unique identifier.
    ///

    class RemoveAllSignalsFromIntTx;
    typedef std::shared_ptr<RemoveAllSignalsFromIntTx> RemoveAllSignalsFromIntTxPtr;
    
    
    class RemoveAllSignalsFromIntTx : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      RemoveAllSignalsFromIntTx();

      RemoveAllSignalsFromIntTx(const std::string& transmitterId);

      static RemoveAllSignalsFromIntTxPtr create(const std::string& transmitterId);
      static RemoveAllSignalsFromIntTxPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** transmitterId ****
      std::string transmitterId() const;
      void setTransmitterId(const std::string& transmitterId);
    };
    
  }
}

