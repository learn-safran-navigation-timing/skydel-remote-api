#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the SV Data Update Mode.
    ///
    /// 
    ///

    class GetSVDataUpdateMode;
    typedef std::shared_ptr<GetSVDataUpdateMode> GetSVDataUpdateModePtr;
    
    
    class GetSVDataUpdateMode : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSVDataUpdateMode();

      static GetSVDataUpdateModePtr create();
      static GetSVDataUpdateModePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

