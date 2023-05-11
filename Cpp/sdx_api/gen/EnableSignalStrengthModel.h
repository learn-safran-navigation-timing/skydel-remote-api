#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set signal strength model Enable/Disable which affect satellite transmission strength based on their elevation angle
    ///
    /// Name    Type Description
    /// ------- ---- -----------------------------------------------------------
    /// Enabled bool If true, signal strengh model is enabled for all satellites
    ///

    class EnableSignalStrengthModel;
    typedef std::shared_ptr<EnableSignalStrengthModel> EnableSignalStrengthModelPtr;
    
    
    class EnableSignalStrengthModel : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EnableSignalStrengthModel();

      EnableSignalStrengthModel(bool enabled);

      static EnableSignalStrengthModelPtr create(bool enabled);
      static EnableSignalStrengthModelPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    
  }
}

