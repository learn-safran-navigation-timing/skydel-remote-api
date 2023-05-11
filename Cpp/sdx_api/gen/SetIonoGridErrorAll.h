#pragma once

#include <memory>
#include "command_base.h"

#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set Error offsets in the ionospheric grid.  The array is zero based, the index 0 in a band array is for the IGP with an index 1, etc.
    ///
    /// Name Type               Description
    /// ---- ------------------ -----------------------------------------------------------------------
    /// Grid array array double Array containing each band, each band is an array containing the errors
    ///

    class SetIonoGridErrorAll;
    typedef std::shared_ptr<SetIonoGridErrorAll> SetIonoGridErrorAllPtr;
    
    
    class SetIonoGridErrorAll : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetIonoGridErrorAll();

      SetIonoGridErrorAll(const std::vector<std::vector<double>>& grid);

      static SetIonoGridErrorAllPtr create(const std::vector<std::vector<double>>& grid);
      static SetIonoGridErrorAllPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** grid ****
      std::vector<std::vector<double>> grid() const;
      void setGrid(const std::vector<std::vector<double>>& grid);
    };
    
  }
}

