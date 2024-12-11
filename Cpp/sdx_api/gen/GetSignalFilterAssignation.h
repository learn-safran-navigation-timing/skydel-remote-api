#pragma once

#include <memory>
#include "command_base.h"

#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Returns filter names assigned to requested signals.
    ///
    /// Name        Type         Description
    /// ----------- ------------ --------------------------------------------------------------------------------
    /// SignalArray array string An array of signals.
    ///                          Accepted values are: "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L2ME",
    ///                                               "L2MR", "L5", "G1", "G2", "E1", "E1PRS", "E5a", "E5b",
    ///                                               "E5AltBOC", "E6BC", "E6PRS", "B1", "B2", "B1C", "B2a",
    ///                                               "B3I", "SBASL1", "SBASL5", "QZSSL1CA", "QZSSL1CB",
    ///                                               "QZSSL1C", "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S",
    ///                                               "QZSSL6", "NAVICL1", "NAVICL5", "NAVICS", "PULSARXL" and
    ///                                               "PULSARX1"
    ///

    class GetSignalFilterAssignation;
    typedef std::shared_ptr<GetSignalFilterAssignation> GetSignalFilterAssignationPtr;
    
    
    class GetSignalFilterAssignation : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSignalFilterAssignation();

      GetSignalFilterAssignation(const std::vector<std::string>& signalArray);

      static GetSignalFilterAssignationPtr create(const std::vector<std::string>& signalArray);
      static GetSignalFilterAssignationPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** signalArray ****
      std::vector<std::string> signalArray() const;
      void setSignalArray(const std::vector<std::string>& signalArray);
    };
    
  }
}

