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
    /// result of GetPseudorangeRamps
    ///
    /// Name   Type         Description
    /// ------ ------------ ----------------------------------------------------------------------------------------------------------
    /// System string       "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Prn    int          Satellite PRN number for GPS, Galileo, BeiDou and SBAS. Slot number for GLONASS. SV ID for QZSS and NavIC.
    /// Ids    array string List of all the pseudorange ramps IDs for this satellite of system
    ///

    class GetPseudorangeRampsResult;
    typedef std::shared_ptr<GetPseudorangeRampsResult> GetPseudorangeRampsResultPtr;
    
    
    class GetPseudorangeRampsResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetPseudorangeRampsResult();

      GetPseudorangeRampsResult(CommandBasePtr relatedCommand, const std::string& system, int prn, const std::vector<std::string>& ids);
  
      static GetPseudorangeRampsResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int prn, const std::vector<std::string>& ids);
      static GetPseudorangeRampsResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** ids ****
      std::vector<std::string> ids() const;
      void setIds(const std::vector<std::string>& ids);
    };
  }
}

