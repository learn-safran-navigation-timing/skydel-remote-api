#pragma once

#include <memory>
#include "command_base.h"

#include <map>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Assigns filters to signals by name; accepted filter values are "None" and "Default".
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

    class SetSignalFilterAssignation;
    typedef std::shared_ptr<SetSignalFilterAssignation> SetSignalFilterAssignationPtr;
    
    
    class SetSignalFilterAssignation : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetSignalFilterAssignation();

      SetSignalFilterAssignation(const std::map<std::string, std::string>& signalFilterDict);

      static SetSignalFilterAssignationPtr create(const std::map<std::string, std::string>& signalFilterDict);
      static SetSignalFilterAssignationPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** signalFilterDict ****
      std::map<std::string, std::string> signalFilterDict() const;
      void setSignalFilterDict(const std::map<std::string, std::string>& signalFilterDict);
    };
    
  }
}

