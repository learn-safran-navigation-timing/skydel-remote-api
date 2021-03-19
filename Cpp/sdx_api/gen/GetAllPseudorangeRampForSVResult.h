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
    /// result of GetAllPseudorangeRampForSV
    ///
    /// Name   Type         Description
    /// ------ ------------ ------------------------------------------------------------------
    /// System string       "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// SvId   int          The satellite's SV ID.
    /// Ids    array string List of all the pseudorange ramps IDs for this system's satellite.
    ///

    class GetAllPseudorangeRampForSVResult;
    typedef std::shared_ptr<GetAllPseudorangeRampForSVResult> GetAllPseudorangeRampForSVResultPtr;
    
    
    class GetAllPseudorangeRampForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetAllPseudorangeRampForSVResult();

      GetAllPseudorangeRampForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::vector<std::string>& ids);
  
      static GetAllPseudorangeRampForSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::vector<std::string>& ids);
      static GetAllPseudorangeRampForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** ids ****
      std::vector<std::string> ids() const;
      void setIds(const std::vector<std::string>& ids);
    };
  }
}

