#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <map>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSignalFilterAssignation.
    ///
    /// Name             Type               Description
    /// ---------------- ------------------ --------------------------------------------------------------------------------
    /// SignalFilterDict dict string:string A dictionary of signal filter pairs.
    ///                                     Accepted keys are: "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L2ME",
    ///                                                        "L2MR", "L5", "G1", "G2", "E1", "E1PRS", "E5a", "E5b",
    ///                                                        "E5AltBOC", "E6BC", "E6PRS", "B1", "B2", "B1C", "B2a", "B3I",
    ///                                                        "SBASL1", "SBASL5", "QZSSL1CA", "QZSSL1CB", "QZSSL1C",
    ///                                                        "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S", "QZSSL6",
    ///                                                        "NAVICL1", "NAVICL5", "NAVICS", "PULSARXL", "PULSARX1" and
    ///                                                        "PULSARX5"
    ///

    class GetSignalFilterAssignationResult;
    typedef std::shared_ptr<GetSignalFilterAssignationResult> GetSignalFilterAssignationResultPtr;
    
    
    class GetSignalFilterAssignationResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSignalFilterAssignationResult();

      GetSignalFilterAssignationResult(const std::map<std::string, std::string>& signalFilterDict);

      GetSignalFilterAssignationResult(CommandBasePtr relatedCommand, const std::map<std::string, std::string>& signalFilterDict);

      static GetSignalFilterAssignationResultPtr create(const std::map<std::string, std::string>& signalFilterDict);

      static GetSignalFilterAssignationResultPtr create(CommandBasePtr relatedCommand, const std::map<std::string, std::string>& signalFilterDict);
      static GetSignalFilterAssignationResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** signalFilterDict ****
      std::map<std::string, std::string> signalFilterDict() const;
      void setSignalFilterDict(const std::map<std::string, std::string>& signalFilterDict);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetSignalFilterAssignationResult);
  }
}

