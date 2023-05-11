#pragma once

#include <memory>
#include "command_base.h"

#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the enabled L1C CNAV2 pages
    ///
    /// Name     Type      Description
    /// -------- --------- -----------------
    /// Messages array int The enabled pages
    ///

    class EnableCnav2Pages;
    typedef std::shared_ptr<EnableCnav2Pages> EnableCnav2PagesPtr;
    
    
    class EnableCnav2Pages : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EnableCnav2Pages();

      EnableCnav2Pages(const std::vector<int>& messages);

      static EnableCnav2PagesPtr create(const std::vector<int>& messages);
      static EnableCnav2PagesPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** messages ****
      std::vector<int> messages() const;
      void setMessages(const std::vector<int>& messages);
    };
    
  }
}

