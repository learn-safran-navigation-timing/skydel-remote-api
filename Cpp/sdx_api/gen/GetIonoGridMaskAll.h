#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get Mask flags in the ionospheric grid for a given service provider. The array is zero based, the index 0 in a band array is for the IGP with an index 1, etc.
    ///
    /// Name            Type   Description
    /// --------------- ------ --------------------
    /// ServiceProvider string The service provider
    ///

    class GetIonoGridMaskAll;
    typedef std::shared_ptr<GetIonoGridMaskAll> GetIonoGridMaskAllPtr;
    
    
    class GetIonoGridMaskAll : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIonoGridMaskAll();

      GetIonoGridMaskAll(const std::string& serviceProvider);

      static GetIonoGridMaskAllPtr create(const std::string& serviceProvider);
      static GetIonoGridMaskAllPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** serviceProvider ****
      std::string serviceProvider() const;
      void setServiceProvider(const std::string& serviceProvider);
    };
    
  }
}

