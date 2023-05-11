#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get Error offsets in the ionospheric grid.  The array is zero based, the index 0 in a band array is for the IGP with an index 1, etc.
    ///
    /// 
    ///

    class GetIonoGridErrorAll;
    typedef std::shared_ptr<GetIonoGridErrorAll> GetIonoGridErrorAllPtr;
    
    
    class GetIonoGridErrorAll : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIonoGridErrorAll();

      static GetIonoGridErrorAllPtr create();
      static GetIonoGridErrorAllPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

