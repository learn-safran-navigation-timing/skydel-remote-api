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
    /// Set the service provider of all the SBAS satellites.
    ///
    /// Name             Type         Description
    /// ---------------- ------------ -----------------------------------------------------------------------------------------------------------------------------------------------------------
    /// ServiceProviders array string Service provider value to set for each satellite. Zero based index (index 0 => Service provider for SV ID 1, index 1 => Service provider for SV ID 2, etc).
    ///

    class SetSbasServiceProviderForEachSV;
    typedef std::shared_ptr<SetSbasServiceProviderForEachSV> SetSbasServiceProviderForEachSVPtr;
    
    
    class SetSbasServiceProviderForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetSbasServiceProviderForEachSV();

      SetSbasServiceProviderForEachSV(const std::vector<std::string>& serviceProviders);

      static SetSbasServiceProviderForEachSVPtr create(const std::vector<std::string>& serviceProviders);
      static SetSbasServiceProviderForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** serviceProviders ****
      std::vector<std::string> serviceProviders() const;
      void setServiceProviders(const std::vector<std::string>& serviceProviders);
    };
    
  }
}

