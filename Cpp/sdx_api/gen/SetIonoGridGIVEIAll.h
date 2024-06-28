#pragma once

#include <memory>
#include "command_base.h"

#include <optional>
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
      static const char* const TargetId;


      SetIonoGridGIVEIAll();

      SetIonoGridGIVEIAll(const std::vector<std::vector<int>>& grid, const std::optional<std::string>& serviceProvider = {});

      static SetIonoGridGIVEIAllPtr create(const std::vector<std::vector<int>>& grid, const std::optional<std::string>& serviceProvider = {});
      static SetIonoGridGIVEIAllPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** grid ****
      std::vector<std::vector<int>> grid() const;
      void setGrid(const std::vector<std::vector<int>>& grid);


      // **** serviceProvider ****
      std::optional<std::string> serviceProvider() const;
      void setServiceProvider(const std::optional<std::string>& serviceProvider);
    };
    
  }
}

