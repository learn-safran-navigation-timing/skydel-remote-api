#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get infos about the QZSS CNAV2 message modification with this ID.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Unique identifier of the event
    ///

    class GetMessageModificationToQzssCNav2;
    typedef std::shared_ptr<GetMessageModificationToQzssCNav2> GetMessageModificationToQzssCNav2Ptr;
    
    
    class GetMessageModificationToQzssCNav2 : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetMessageModificationToQzssCNav2();

      GetMessageModificationToQzssCNav2(const std::string& id);

      static GetMessageModificationToQzssCNav2Ptr create(const std::string& id);
      static GetMessageModificationToQzssCNav2Ptr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

