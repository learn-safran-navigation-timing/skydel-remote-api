#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Quit/Exit Skydel. Simulation must be stopped to be able to quit Skydel
    ///
    /// Name      Type Description
    /// --------- ---- --------------------------------------------------------
    /// ForceQuit bool Force to quit Skydel even if current config is not saved
    ///

    class Quit;
    typedef std::shared_ptr<Quit> QuitPtr;
    
    
    class Quit : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      Quit();

      Quit(bool forceQuit);

      static QuitPtr create(bool forceQuit);
      static QuitPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** forceQuit ****
      bool forceQuit() const;
      void setForceQuit(bool forceQuit);
    };
    
  }
}

