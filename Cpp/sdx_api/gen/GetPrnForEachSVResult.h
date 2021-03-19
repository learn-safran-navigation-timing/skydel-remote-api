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
    /// Result of GetPrnForEachSV
    ///
    /// Name   Type      Description
    /// ------ --------- --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Signal string    Accepted signal keys: "L1CA", "L1C", "L2C", "L5", "G1", "G2", "E1", "E5a", "E5b", "E6BC", "B1", "B2", "B1C", "B2a", "SBASL1", "SBASL5", "QZSSL1CA", "QZSSL1C", "QZSSL5", "QZSSL1S", "QZSSL5S", "NAVICL5"
    /// Prn    array int PRN value to set for each satellite. Zero based index (index 0 => PRN for SV ID 1, index 1 => PRN for SV ID 2, etc)
    ///

    class GetPrnForEachSVResult;
    typedef std::shared_ptr<GetPrnForEachSVResult> GetPrnForEachSVResultPtr;
    
    
    class GetPrnForEachSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetPrnForEachSVResult();

      GetPrnForEachSVResult(CommandBasePtr relatedCommand, const std::string& signal, const std::vector<int>& prn);
  
      static GetPrnForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::string& signal, const std::vector<int>& prn);
      static GetPrnForEachSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** prn ****
      std::vector<int> prn() const;
      void setPrn(const std::vector<int>& prn);
    };
  }
}

