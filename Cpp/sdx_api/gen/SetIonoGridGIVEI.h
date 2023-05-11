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
    /// Set the GIVEI for a ionospheric grid point
    ///
    /// Name            Type            Description
    /// --------------- --------------- -------------------------------
    /// Band            int             The ionospheric grid band index
    /// Point           int             The IGP index
    /// GiveI           int             The GIVEI at the IGP
    /// ServiceProvider optional string The service provider (optional)
    ///

    class SetIonoGridGIVEI;
    typedef std::shared_ptr<SetIonoGridGIVEI> SetIonoGridGIVEIPtr;
    
    
    class SetIonoGridGIVEI : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetIonoGridGIVEI();

      SetIonoGridGIVEI(int band, int point, int giveI, const Sdx::optional<std::string>& serviceProvider = {});

      static SetIonoGridGIVEIPtr create(int band, int point, int giveI, const Sdx::optional<std::string>& serviceProvider = {});
      static SetIonoGridGIVEIPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** band ****
      int band() const;
      void setBand(int band);


      // **** point ****
      int point() const;
      void setPoint(int point);


      // **** giveI ****
      int giveI() const;
      void setGiveI(int giveI);


      // **** serviceProvider ****
      Sdx::optional<std::string> serviceProvider() const;
      void setServiceProvider(const Sdx::optional<std::string>& serviceProvider);
    };
    
  }
}

