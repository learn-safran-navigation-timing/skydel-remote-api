#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get all the message modification event's IDs for this signal and SV ID.
    ///
    /// Name   Type   Description
    /// ------ ------ ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Signal string Signal key, accepted values : "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L2ME", "L2MR", "L5", "G1", "G2", "E1", "E5a", "E5b", "B1", "B2", "B2a", "B1C", "B3I", "QZSSL1CA", "QZSSL1CB", "QZSSL1S", "NAVICL5", "NAVICS", "SBASL1", "SBASL5" and "PULSARXL"
    /// SvId   int    The satellite's SV ID
    ///

    class GetAllMessageModificationIdsForSignal;
    typedef std::shared_ptr<GetAllMessageModificationIdsForSignal> GetAllMessageModificationIdsForSignalPtr;
    
    
    class GetAllMessageModificationIdsForSignal : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetAllMessageModificationIdsForSignal();

      GetAllMessageModificationIdsForSignal(const std::string& signal, int svId);

      static GetAllMessageModificationIdsForSignalPtr create(const std::string& signal, int svId);
      static GetAllMessageModificationIdsForSignalPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
    
  }
}

