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
    /// Result of GetSbasServiceProviderForEachSV.
    ///
    /// Name             Type         Description
    /// ---------------- ------------ -----------------------------------------------------------------------------------------------------------------------------------------------------------
    /// ServiceProviders array string Service provider value to set for each satellite. Zero based index (index 0 => Service provider for SV ID 1, index 1 => Service provider for SV ID 2, etc).
    ///

    class GetSbasServiceProviderForEachSVResult;
    typedef std::shared_ptr<GetSbasServiceProviderForEachSVResult> GetSbasServiceProviderForEachSVResultPtr;
    
    
    class GetSbasServiceProviderForEachSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSbasServiceProviderForEachSVResult();

      GetSbasServiceProviderForEachSVResult(const std::vector<std::string>& serviceProviders);

      GetSbasServiceProviderForEachSVResult(CommandBasePtr relatedCommand, const std::vector<std::string>& serviceProviders);

      static GetSbasServiceProviderForEachSVResultPtr create(const std::vector<std::string>& serviceProviders);

      static GetSbasServiceProviderForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::vector<std::string>& serviceProviders);
      static GetSbasServiceProviderForEachSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** serviceProviders ****
      std::vector<std::string> serviceProviders() const;
      void setServiceProviders(const std::vector<std::string>& serviceProviders);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetSbasServiceProviderForEachSVResult);
  }
}

