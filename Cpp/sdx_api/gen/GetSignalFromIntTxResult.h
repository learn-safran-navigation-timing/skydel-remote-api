#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSignalFromIntTx.
    ///
    /// Name          Type         Description
    /// ------------- ------------ ------------------------------------------------------------------------------------
    /// IdTransmitter string       Transmitter unique identifier.
    /// SignalType    string       Type of signal. Accepted signals are : "CW", "Chirp", "Pulse", "BPSK", "BOC", "AWGN"
    /// IdsSignal     array string List of signal ID for this interferences transmitter and this signal type.
    ///

    class GetSignalFromIntTxResult;
    typedef std::shared_ptr<GetSignalFromIntTxResult> GetSignalFromIntTxResultPtr;
    
    
    class GetSignalFromIntTxResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSignalFromIntTxResult();

      GetSignalFromIntTxResult(const std::string& idTransmitter, const std::string& signalType, const std::vector<std::string>& idsSignal);

      GetSignalFromIntTxResult(CommandBasePtr relatedCommand, const std::string& idTransmitter, const std::string& signalType, const std::vector<std::string>& idsSignal);

      static GetSignalFromIntTxResultPtr create(const std::string& idTransmitter, const std::string& signalType, const std::vector<std::string>& idsSignal);

      static GetSignalFromIntTxResultPtr create(CommandBasePtr relatedCommand, const std::string& idTransmitter, const std::string& signalType, const std::vector<std::string>& idsSignal);
      static GetSignalFromIntTxResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** idTransmitter ****
      std::string idTransmitter() const;
      void setIdTransmitter(const std::string& idTransmitter);


      // **** signalType ****
      std::string signalType() const;
      void setSignalType(const std::string& signalType);


      // **** idsSignal ****
      std::vector<std::string> idsSignal() const;
      void setIdsSignal(const std::vector<std::string>& idsSignal);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetSignalFromIntTxResult);
  }
}

