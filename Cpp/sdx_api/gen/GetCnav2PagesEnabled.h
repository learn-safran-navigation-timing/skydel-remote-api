#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the enabled L1C CNAV2 pages
    ///
    /// 
    ///

    class GetCnav2PagesEnabled;
    typedef std::shared_ptr<GetCnav2PagesEnabled> GetCnav2PagesEnabledPtr;
    
    
    class GetCnav2PagesEnabled : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetCnav2PagesEnabled();

      static GetCnav2PagesEnabledPtr create();
      static GetCnav2PagesEnabledPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

