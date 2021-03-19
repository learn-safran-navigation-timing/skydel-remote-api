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
    /// Result of GetPrnsEnabled
    ///
    /// Name    Type       Description
    /// ------- ---------- ------------------------------------------------------------------------------------------------------
    /// System  string     The satellites' constellation. Can be "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC"
    /// Enabled array bool Array of present/absent flags for the constellation
    ///

    class GetPrnsEnabledResult;
    typedef std::shared_ptr<GetPrnsEnabledResult> GetPrnsEnabledResultPtr;
    
    
    class GetPrnsEnabledResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetPrnsEnabledResult();

      GetPrnsEnabledResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled);
  
      static GetPrnsEnabledResultPtr create(CommandBasePtr relatedCommand, const std::string& system, const std::vector<bool>& enabled);
      static GetPrnsEnabledResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** enabled ****
      std::vector<bool> enabled() const;
      void setEnabled(const std::vector<bool>& enabled);
    };
  }
}

