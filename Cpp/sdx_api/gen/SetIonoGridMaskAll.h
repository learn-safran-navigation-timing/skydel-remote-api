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
    /// Set Mask flags in the ionospheric grid for a given service provider. The array is zero based, the index 0 in a band array is for the IGP with an index 1, etc.
    ///
    /// Name            Type             Description
    /// --------------- ---------------- ----------------------------------------------------------------------
    /// ServiceProvider string           The service provider
    /// Grid            array array bool Array containing each band, each band is an array containing the flags
    ///

    class SetIonoGridMaskAll;
    typedef std::shared_ptr<SetIonoGridMaskAll> SetIonoGridMaskAllPtr;
    
    
    class SetIonoGridMaskAll : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetIonoGridMaskAll();

      SetIonoGridMaskAll(const std::string& serviceProvider, const std::vector<std::vector<bool>>& grid);

      static SetIonoGridMaskAllPtr create(const std::string& serviceProvider, const std::vector<std::vector<bool>>& grid);
      static SetIonoGridMaskAllPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** serviceProvider ****
      std::string serviceProvider() const;
      void setServiceProvider(const std::string& serviceProvider);


      // **** grid ****
      std::vector<std::vector<bool>> grid() const;
      void setGrid(const std::vector<std::vector<bool>>& grid);
    };
    
  }
}

