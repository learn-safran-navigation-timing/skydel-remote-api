#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetUdreiForEachSV.
    ///
    /// Name   Type      Description
    /// ------ --------- --------------------------------------------------------------------------------------------------------------------------
    /// System string    "GPS" or "SBAS".
    /// Udreis array int UDREI value to set for each satellite. Zero based index (index 0 => UDREI for SV ID 1, index 1 => UDREI for SV ID 2, etc).
    ///

    class GetUdreiForEachSVResult;
    typedef std::shared_ptr<GetUdreiForEachSVResult> GetUdreiForEachSVResultPtr;
    
    
    class GetUdreiForEachSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetUdreiForEachSVResult();

      GetUdreiForEachSVResult(const std::string& system, const std::vector<int>& udreis);

      GetUdreiForEachSVResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<int>& udreis);

      static GetUdreiForEachSVResultPtr create(const std::string& system, const std::vector<int>& udreis);

      static GetUdreiForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, const std::vector<int>& udreis);
      static GetUdreiForEachSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** udreis ****
      std::vector<int> udreis() const;
      void setUdreis(const std::vector<int>& udreis);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetUdreiForEachSVResult);
  }
}

