#pragma once

#include <memory>
#include "command_result.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetAllSignalsFromIntTx.
    ///
    /// Name      Type         Description
    /// --------- ------------ -----------------------------------------------------
    /// Id        string       Transmitter unique identifier.
    /// IdsSignal array string List of signal ID for this interferences transmitter.
    ///

    class GetAllSignalsFromIntTxResult;
    typedef std::shared_ptr<GetAllSignalsFromIntTxResult> GetAllSignalsFromIntTxResultPtr;
    
    
    class GetAllSignalsFromIntTxResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetAllSignalsFromIntTxResult();

      GetAllSignalsFromIntTxResult(CommandBasePtr relatedCommand, const std::string& id, const std::vector<std::string>& idsSignal);
  
      static GetAllSignalsFromIntTxResultPtr create(CommandBasePtr relatedCommand, const std::string& id, const std::vector<std::string>& idsSignal);
      static GetAllSignalsFromIntTxResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);


      // **** idsSignal ****
      std::vector<std::string> idsSignal() const;
      void setIdsSignal(const std::vector<std::string>& idsSignal);
    };
  }
}

