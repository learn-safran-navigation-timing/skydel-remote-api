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
    /// Get the GIVEI for a ionospheric grid point
    ///
    /// Name            Type            Description
    /// --------------- --------------- -------------------------------
    /// Band            int             The ionospheric grid band index
    /// Point           int             The IGP index
    /// ServiceProvider optional string The service provider (optional)
    ///

    class GetIonoGridGIVEI;
    typedef std::shared_ptr<GetIonoGridGIVEI> GetIonoGridGIVEIPtr;
    
    
    class GetIonoGridGIVEI : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetIonoGridGIVEI();

      GetIonoGridGIVEI(int band, int point, const Sdx::optional<std::string>& serviceProvider = {});

      static GetIonoGridGIVEIPtr create(int band, int point, const Sdx::optional<std::string>& serviceProvider = {});
      static GetIonoGridGIVEIPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** band ****
      int band() const;
      void setBand(int band);


      // **** point ****
      int point() const;
      void setPoint(int point);


      // **** serviceProvider ****
      Sdx::optional<std::string> serviceProvider() const;
      void setServiceProvider(const Sdx::optional<std::string>& serviceProvider);
    };
    
  }
}

