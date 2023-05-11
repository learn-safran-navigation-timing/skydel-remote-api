#pragma once

#include <memory>
#include "command_base.h"

#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the PRN for each satellite for specified signals.
    ///
    /// Name   Type      Description
    /// ------ --------- ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Signal string    Accepted signal keys: "L1CA", "L1C", "L2C", "L5", "E1", "E6BC", "B1", "B2", "B1C", "B2a", "B3I", "SBASL1", "SBASL5", "QZSSL1CA", "QZSSL1CB", "QZSSL1C", "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S", "NAVICL5"
    /// Prn    array int PRN value to set for each satellite. Zero based index (index 0 => PRN for SV ID 1, index 1 => PRN for SV ID 2, etc)
    ///

    class SetPrnForEachSV;
    typedef std::shared_ptr<SetPrnForEachSV> SetPrnForEachSVPtr;
    
    
    class SetPrnForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetPrnForEachSV();

      SetPrnForEachSV(const std::string& signal, const std::vector<int>& prn);

      static SetPrnForEachSVPtr create(const std::string& signal, const std::vector<int>& prn);
      static SetPrnForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** prn ****
      std::vector<int> prn() const;
      void setPrn(const std::vector<int>& prn);
    };
    
  }
}

