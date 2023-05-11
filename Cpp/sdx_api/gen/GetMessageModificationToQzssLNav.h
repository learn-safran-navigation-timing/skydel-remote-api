#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get infos about the QZSS LNAV message modification with this ID.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Unique identifier of the event
    ///

    class GetMessageModificationToQzssLNav;
    typedef std::shared_ptr<GetMessageModificationToQzssLNav> GetMessageModificationToQzssLNavPtr;
    
    
    class GetMessageModificationToQzssLNav : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetMessageModificationToQzssLNav();

      GetMessageModificationToQzssLNav(const std::string& id);

      static GetMessageModificationToQzssLNavPtr create(const std::string& id);
      static GetMessageModificationToQzssLNavPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

