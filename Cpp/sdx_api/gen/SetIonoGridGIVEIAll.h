#pragma once

#include <memory>
#include "command_base.h"

#include "sdx_optional.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set GIVEI in the ionospheric grid.  The array is zero based, the index 0 in a band array is for the IGP with an index 1, etc.
    ///
    /// Name            Type            Description
    /// --------------- --------------- ----------------------------------------------------------------------
    /// Grid            array array int Array containing each band, each band is an array containing the GIVEI
    /// ServiceProvider optional string The service provider (optional)
    ///

    class SetIonoGridGIVEIAll;
    typedef std::shared_ptr<SetIonoGridGIVEIAll> SetIonoGridGIVEIAllPtr;
    
    
    class SetIonoGridGIVEIAll : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetIonoGridGIVEIAll();

      SetIonoGridGIVEIAll(const std::vector<std::vector<int>>& grid, const Sdx::optional<std::string>& serviceProvider = {});

      static SetIonoGridGIVEIAllPtr create(const std::vector<std::vector<int>>& grid, const Sdx::optional<std::string>& serviceProvider = {});
      static SetIonoGridGIVEIAllPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** grid ****
      std::vector<std::vector<int>> grid() const;
      void setGrid(const std::vector<std::vector<int>>& grid);


      // **** serviceProvider ****
      Sdx::optional<std::string> serviceProvider() const;
      void setServiceProvider(const Sdx::optional<std::string>& serviceProvider);
    };
    
  }
}

