#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get all signal ID from this interference transmitters and this signal type. If the signal type is invalid, get the IDs of CW type.
    ///
    /// Name          Type   Description
    /// ------------- ------ --------------------------------------------------------------------------------------
    /// IdTransmitter string Transmitter unique identifier.
    /// SignalType    string Type of signal. Authorized signals are : "CW", "Chirp", "Pulse", "BPSK", "BOC", "AWGN"
    ///

    class GetSignalFromIntTx;
    typedef std::shared_ptr<GetSignalFromIntTx> GetSignalFromIntTxPtr;
    
    
    class GetSignalFromIntTx : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSignalFromIntTx();

      GetSignalFromIntTx(const std::string& idTransmitter, const std::string& signalType);
  
      static GetSignalFromIntTxPtr create(const std::string& idTransmitter, const std::string& signalType);
      static GetSignalFromIntTxPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** idTransmitter ****
      std::string idTransmitter() const;
      void setIdTransmitter(const std::string& idTransmitter);


      // **** signalType ****
      std::string signalType() const;
      void setSignalType(const std::string& signalType);
    };
  }
}
