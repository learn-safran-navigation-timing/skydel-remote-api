#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Clear automate page.
    ///
    /// 
    ///

    class ClearAutomatePage;
    typedef std::shared_ptr<ClearAutomatePage> ClearAutomatePagePtr;
    
    
    class ClearAutomatePage : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ClearAutomatePage();

      static ClearAutomatePagePtr create();
      static ClearAutomatePagePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

