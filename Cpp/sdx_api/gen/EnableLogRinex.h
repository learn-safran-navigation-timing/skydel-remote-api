#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable (or disable) ephemeris data logging in RINEX v3.03 format
    ///
    /// Name    Type Description
    /// ------- ---- ------------------------------------------------
    /// Enabled bool If true, files will be created during simulation
    ///

    class EnableLogRinex;
    typedef std::shared_ptr<EnableLogRinex> EnableLogRinexPtr;
    
    
    class EnableLogRinex : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      EnableLogRinex();

      EnableLogRinex(bool enabled);

      static EnableLogRinexPtr create(bool enabled);
      static EnableLogRinexPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    
  }
}

