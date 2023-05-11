#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable (or disable) raw data logging (pseudorange, antenna gain, receiver position, satellite position, etc.)
    ///
    /// Name    Type Description
    /// ------- ---- -----------------------------------------------
    /// Enabled bool If true, file will be created during simulation
    ///

    class EnableLogRaw;
    typedef std::shared_ptr<EnableLogRaw> EnableLogRawPtr;
    
    
    class EnableLogRaw : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EnableLogRaw();

      EnableLogRaw(bool enabled);

      static EnableLogRawPtr create(bool enabled);
      static EnableLogRawPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    
  }
}

