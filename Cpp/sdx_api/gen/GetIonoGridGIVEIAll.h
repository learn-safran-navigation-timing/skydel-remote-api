#pragma once

#include <memory>
#include "command_base.h"

#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get GIVEI in the ionospheric grid.  The array is zero based, the index 0 in a band array is for the IGP with an index 1, etc.
    ///
    /// Name            Type            Description
    /// --------------- --------------- -------------------------------
    /// ServiceProvider optional string The service provider (optional)
    ///

    class GetIonoGridGIVEIAll;
    typedef std::shared_ptr<GetIonoGridGIVEIAll> GetIonoGridGIVEIAllPtr;
    
    
    class GetIonoGridGIVEIAll : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetIonoGridGIVEIAll(const Sdx::optional<std::string>& serviceProvider = {});

      static GetIonoGridGIVEIAllPtr create(const Sdx::optional<std::string>& serviceProvider = {});
      static GetIonoGridGIVEIAllPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** serviceProvider ****
      Sdx::optional<std::string> serviceProvider() const;
      void setServiceProvider(const Sdx::optional<std::string>& serviceProvider);
    };
    
  }
}

