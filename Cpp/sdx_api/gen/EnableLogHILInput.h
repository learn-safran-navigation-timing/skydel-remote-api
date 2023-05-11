#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable (or disable) log of all the data received on the HIL API in a CSV format
    ///
    /// Name    Type Description
    /// ------- ---- ------------------------------------------------
    /// Enabled bool If true, files will be created during simulation
    ///

    class EnableLogHILInput;
    typedef std::shared_ptr<EnableLogHILInput> EnableLogHILInputPtr;
    
    
    class EnableLogHILInput : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EnableLogHILInput();

      EnableLogHILInput(bool enabled);

      static EnableLogHILInputPtr create(bool enabled);
      static EnableLogHILInputPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    
  }
}

