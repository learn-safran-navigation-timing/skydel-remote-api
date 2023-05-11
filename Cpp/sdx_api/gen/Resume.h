#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Resume vehicle motion during simulation.
    ///
    /// 
    ///

    class Resume;
    typedef std::shared_ptr<Resume> ResumePtr;
    
    
    class Resume : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      Resume();

      static ResumePtr create();
      static ResumePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

